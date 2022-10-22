#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BITree { 
	ll MAXN;
	vector<ll> freq;
	void resize(ll n) { 
		freq.resize(n+1);
		MAXN = n;
		memset(&freq[0], 0, (n+1)*sizeof(freq[0])); 
	}
  void insert(int x, ll cnt=1) {
    for ( ; x <= MAXN; x += x & -x) freq[x] += cnt;
      //for (int y = argy; y <= MAXN; y += y & -y) freq[x][y] += cnt;
  }
  ll query(int x) { ll sum = 0;
    for ( ; x; x -= x & -x) sum += freq[x];
      //for (int y = argy; y; y -= y & -y) sum += freq[x][y];
    return sum; }
  void insert_range(int xl,int xr,ll cnt=1) {
	  if (xl <= xr) {
		  insert(xl,cnt); 
		  insert(xr+1,-cnt);
	  }
	  else {
		  insert_range(1, xr, cnt);
		  insert_range(xl, MAXN, cnt);
	  }
  }
  ll query_range(int xl, int xr) { return query(xr) - query(xl-1); }
  int get_nth(ll n) { int x = 1<<30; // assumes non-negative frequencies
    for (int step = x>>1; step; step >>= 1)
      if (x-step > MAXN || freq[x-step] >= n) x -= step; else n -= freq[x-step];
    return x; } };

struct CardPos {
	int prev_in_bit;
	int next_in_bit;
};
struct Card {
	int value;
	int pos_in_bit;
};
bool cmpCard(const Card &a, const Card &b) {
	if (a.value == b.value) return a.pos_in_bit < b.pos_in_bit;
	else return a.value < b.value;
}

BITree position;
vector<Card> cards;

int last_in_deck(int left, int right) {
	int left_end = position.query(cards[left].pos_in_bit);
	int right_end = position.query(cards[right].pos_in_bit);
	if (left_end <= right_end)
		return right;

	int mid;
	while (left <= right) {
		mid = (left+right)/2;
		// first half
		if (position.query(cards[mid].pos_in_bit) >= left_end)
			left = mid+1;
		else
			right = mid-1;
	}
	if (position.query(cards[mid].pos_in_bit) <= right_end)
		return mid-1;
	else
		return mid;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	vector<CardPos> cardpos;
	int freq[100001];
	memset(freq, 0, sizeof(freq));
	//cerr<<""; int compare[100001];

	ll ans = 0;
	int n;
	cin >> n;
	cards.resize(n);
	cardpos.resize(n+1);
	position.resize(n);

	// input cards and initialize bit
	for (int i = 0; i < n; i++) {
		cin >> cards[i].value;
		//cerr<<""; compare[i] = cards[i].value;
		cards[i].pos_in_bit = i+1;
		cardpos[i+1].next_in_bit = (i+1)%n + 1;
		cardpos[(i+1)%n + 1].prev_in_bit = i+1;
		position.insert_range(i+1, n);
		freq[cards[i].value]++;
	}
	sort(cards.begin(), cards.end(), cmpCard);

	// iterate through card values
	int first_card = 1;
	int first, last, shift, cards_left;
	int next, prev, cnext, cprev;
	for (int i = 0; i < n; i++) {
		first = i;
		last = i + freq[cards[i].value] - 1;
		i = last_in_deck(first, last);
		shift = position.query(cards[i].pos_in_bit);
		cards_left = n - first;
		// update ans
		ans += shift;
		
		// debugging output
		//cerr << endl << "loop " << i << ": " << freq[cards[i].value] << " cards of value " << cards[i].value << endl;
		//cerr << "v,p : "; for(int z=0;z<n;z++) { if(compare[z]>=cards[i].value) 
			//cerr << position.query(z+1) << ":" << compare[z] << "   "; } 
		//cerr << endl;
		//cerr << "first_card: " << first_card << endl;
		//cerr << "last_in_deck: " << position.query(cards[i].pos_in_bit) << endl;
		//cerr << "update ans: " << ans << endl;

		// iterate through intervals
		for (int j = 1; j < freq[cards[i].value]; j++) {
			next = cards[((i+1+j) - first)%freq[cards[i].value] + first].pos_in_bit;
			prev = cards[((i+j) - first)%freq[cards[i].value] + first].pos_in_bit;
			// update position
			position.insert_range(prev, next, cards_left - shift - j);
			// remove prev card
			cnext = cardpos[prev].next_in_bit;
			cprev = cardpos[prev].prev_in_bit;
			cardpos[cnext].prev_in_bit = cprev;
			cardpos[cprev].next_in_bit = cnext;
		}

		// deal with end intervals
		next = cards[((i+1) - first)%freq[cards[i].value] + first].pos_in_bit;
		prev = cards[i].pos_in_bit;
		// update position
		position.insert_range(first_card, next, cards_left - shift);
		position.insert_range(prev, cardpos[first_card].prev_in_bit, -shift);
		// remove last card
		cnext = cardpos[prev].next_in_bit;
		cprev = cardpos[prev].prev_in_bit;
		cardpos[cnext].prev_in_bit = cprev;
		cardpos[cprev].next_in_bit = cnext;
		// update first_card
		first_card = cnext;
		// update i
		i = last;
	}
	//cerr << endl << "answer: ";
	cout << ans << endl;

	return 0;
}