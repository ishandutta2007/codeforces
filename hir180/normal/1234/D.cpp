#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 10000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
string s;
int q;
set<int>pos[26];
int main(){
	cin >> s;
	cin >> q;
	rep(i,s.size()) pos[s[i]-'a'].insert(i);
	rep(i,q){
		int id; scanf("%d",&id);
		if(id == 1){
			int a; scanf("%d",&a);
			a--;
			pos[s[a]-'a'].erase(a);
			char ch ; scanf(" %c",&ch);
			pos[ch-'a'].insert(a);
			s[a] = ch;
		}
		else{
			int a,b; scanf("%d%d",&a,&b);
			a--; b--;
			int ans =0;
			rep(i,26){
				auto it = pos[i].lower_bound(a);
				if(it != pos[i].end() && (*it) <= b) ans++;
			}
			printf("%d\n",ans);
		}
	}
}