// Suffix Array from http://apps.topcoder.com/forums/?module=Thread&threadID=627379&start=0&mc=39#1038914

#include <bits/stdc++.h>
using namespace std;
const int nax = 3e6 + 5, inf = 1e9 + 5;
int H, str[nax], Bucket[nax], nBucket[nax]; // needed for Suffix Array
 
struct Suffix {
	int idx; // Suffix starts at idx, i.e. it's str[ idx .. L-1 ]
	bool operator<(const Suffix& sfx) const
	// Compares two suffixes based on their first 2H symbols,
	// assuming we know the result for H symbols.
	{
		if(H == 0) return str[idx] < str[sfx.idx];
		else if(Bucket[idx] == Bucket[sfx.idx]) 
			return (Bucket[idx+H] < Bucket[sfx.idx+H]);
		else
			return (Bucket[idx] < Bucket[sfx.idx]);
	}
	bool operator==(const Suffix& sfx) const
	{
		return !(*this < sfx) && !(sfx < *this);
	}
} Pos[nax];
int UpdateBuckets(int L) {
	int start = 0, id = 0, c = 0;
	for(int i = 0; i < L; i++)
	{
		/*
			If Pos[i] is not equal to Pos[i-1], a new bucket has started.
		*/
		if(i != 0 && !(Pos[i] == Pos[i-1]))
		{
			start = i;
			id++;
		}
		if(i != start) // if there is bucket with size larger than 1, we should continue ...
			c = 1;
		nBucket[Pos[i].idx] = id; // Bucket for suffix starting at Pos[i].idx is id ...
	}
	memcpy(Bucket, nBucket, 4 * L);
	return c;
}
void SuffixSort(int L) {
	for(int i = 0; i < L; i++) Pos[i].idx = i;
	// H == 0, Sort based on first Character.
	sort(Pos, Pos + L);
	// Create initial buckets
	int c = UpdateBuckets(L);
	for(H=1;c;H *= 2) {
		// Sort based on first 2*H symbols, assuming that we have sorted based on first H character
		sort(Pos, Pos+L);
		// Update Buckets based on first 2*H symbols
		c = UpdateBuckets(L);
	}
}

int sa[nax], inv_sa[nax]; // needed for calculating LCP

long long count_substrings(vector<int> input) {
	long long answer = 0;
	for(int i = 0; i < (int) input.size(); ++i) str[i] = input[i];
	int n = input.size();
	SuffixSort(n + 1);
	// calculate LCP
	for(int i = 0; i < n; ++i) {
		answer += n - Pos[i+1].idx;
		sa[i] = Pos[i+1].idx;
		inv_sa[sa[i]] = i;
	}
	int lcp = 0;
	for(int i = 0; i < n; ++i) {
		int k = inv_sa[i];
		if(k == 0) continue;
		int j = sa[k-1];
		while(str[i+lcp] == str[j+lcp]) ++lcp;
		answer -= lcp;
		if(lcp > 0) --lcp;
	}
	return answer;
}

map<int,int> m[nax];
int getHash(int a, int b) {
	if(m[a].count(b)) return m[a][b];
	static int T = 2;
	return m[a][b] = T++;
}

vector<int> global;

void consider(string ss) { // gets one valid gragment, e.g. ()(())()()
	assert(!ss.empty());
	// cout << ss << " ";
	ss = '(' + ss + ')';
	// cout << ss << "\n";
	int n = ss.length();
	vector<vector<int>> stack;
	for(int i = 0; i < n; ++i) {
		if(ss[i] == '(') stack.push_back(vector<int>{1});
		else {
			vector<int> & w = stack.back();
			for(int j = 1; j < (int) w.size(); ++j)
				global.push_back(w[j]);
			static int T = -1;
			global.push_back(T--);
			if(i == n - 1) return;
			// for(int x : w) printf("%d ", x);
			int h = w[0];
			for(int j = 1; j < (int) w.size(); ++j)
				h = getHash(h, w[j]);
			stack.pop_back();
			assert(!stack.empty());
			stack.back().push_back(getHash(h, 0));
			// printf("   h = %d (%d)\n", h, getHash(h, 0));
		}
	}
}

char sl[nax];
int pref[nax], minSuf[nax];
int toValue(char z) { return z == '(' ? 1 : -1; }

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	/*set<string> brute;
	for(int i = 0; i < n; ++i) {
		string ss;
		int cnt = 0;
		for(int j = i; j < n; ++j) {
			char z = sl[j];
			ss += z;
			if(z == '(') ++cnt;
			else --cnt;
			if(cnt < 0) break;
			if(cnt == 0) brute.insert(ss);
		}
	}
	printf("%d\n", (int) brute.size());*/
	// find valid fragments, e.g. set {(), (()), ()()()} for ))())))(())(((()()()
	for(int i = 0; i < n; ++i) {
		if(i) pref[i] = pref[i-1];
		pref[i] += toValue(sl[i]);
	}
	minSuf[n] = inf;
	for(int i = n - 1; i >= 0; --i)
		minSuf[i] = min(minSuf[i+1], pref[i]);
	for(int i = 0; i < n; ++i) {
		string ss;
		while(sl[i] == '(' && minSuf[i+1] < pref[i]) {
			ss += sl[i];
			int val = toValue(sl[i]);
			while(val) {
				++i;
				val += toValue(sl[i]);
				ss += sl[i];
			}
			++i;
		}
		if(ss.empty()) {}//printf("X");
		else {
			consider(ss);
			--i;
		}
	}
	if(global.empty()) {
		puts("0");
		return 0;
	}
	long long answer = (long long) global.size() * (global.size() + 1) / 2;
	for(int i = 0; i < (int) global.size(); ++i) if(global[i] > 0) {
		int j = i;
		while(j + 1 < (int) global.size() && global[j+1] > 0) ++j;
		long long tmp = j - i + 1;
		answer -= tmp * (tmp + 1) / 2;
		i = j;
	}
	printf("%lld\n", count_substrings(global) - answer + 1);
	return 0;
}