#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char s[1000000];
int len;
int curInd;
set<int> used1, used2;
vector<pair<int, int> > V;

struct Trie{
	int num1, num2;
	int inTree1, inTree2;
	vector<int> ind1, ind2;
	Trie* child[26];

	Trie(){
		num1=0;
		inTree1=0;
		num2=0;
		inTree2=0;
		rep(i,0,26)
			child[i]=NULL;
	}

	void rec1(int pos){
		++inTree1;
		ind1.push_back(curInd);
		if(pos == len){
			++num1;
			return;
		}
		int c=s[pos]-'a';
		if(child[c] == NULL){
			child[c] = new Trie();
		}
		child[c]->rec1(pos+1);
	}
	void rec2(int pos){
		++inTree2;
		ind2.push_back(curInd);
		if(pos == len){
			++num2;
			return;
		}
		int c=s[pos]-'a';
		if(child[c] == NULL){
			child[c] = new Trie();
		}
		child[c]->rec2(pos+1);
	}

	int rec3(){
		int ans=min(inTree1,inTree2);
		for(int i=0; i < 26; ++i)
			if(child[i] != NULL){
				ans += child[i]->rec3();
			}
		vector<int> pool1, pool2;
		for(int i=0; i < ind1.size(); ++i){
			int j=ind1[i];
			if(used1.find(j) == used1.end()){
				pool1.push_back(j);
			}
		}
		for(int i=0; i < ind2.size(); ++i){
			int j=ind2[i];
			if(used2.find(j) == used2.end()){
				pool2.push_back(j);
			}
		}
		for(int i=0; i < min(pool1.size(), pool2.size()); ++i){
			V.push_back(make_pair(pool1[i], pool2[i]));
			used1.insert(pool1[i]);
			used2.insert(pool2[i]);
		}
		return ans;
	}
};

Trie root;

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		curInd=i;
		scanf("%s", s);
		len=strlen(s);
		root.rec1(0);
	}
	rep(i,0,n){
		curInd=i;
		scanf("%s", s);
		len=strlen(s);
		root.rec2(0);
	}
	printf("%d\n", root.rec3()-n);
	rep(i,0,n){
		printf("%d %d\n", V[i].first+1, V[i].second+1);
	}
}