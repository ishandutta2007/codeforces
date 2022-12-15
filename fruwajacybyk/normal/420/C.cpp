#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define max_n 300005

using namespace std;

map<int,int> glosy;
map<PII,int> parki;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,0,n){
		int a,b; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);

		if(glosy.find(a)!=glosy.end()) glosy[a]++;
		else glosy.insert(mp(a,1));

		if(glosy.find(b)!=glosy.end()) glosy[b]++;
		else glosy.insert(mp(b,1));

		if(parki.find(mp(a,b))!=parki.end()) parki[mp(a,b)]++;
		else parki.insert(mp(mp(a,b),1));
	}
	if(m==0){
		cout<<(n*1LL*(n-1LL))/2LL<<endl;
		return 0;
	}
	lint res = 0LL;
	
	VI v;
	for(map<int,int>::iterator it = glosy.begin();it!=glosy.end();it++) v.pb(it->nd);

	int jeszcze = n-v.size();

	sort(v.begin(),v.end());
	int k = v.size();
	FOR(i,0,k){
		VI::iterator it2 = lower_bound(v.begin(),v.end(),m-v[i]);
		int ile = (v.end()-it2);
		if(v[i]+v[i]>=m) ile--;
		if(v[i]>=m) ile+=2*jeszcze;
		res+=ile*1LL;
	}
	res=res/2;


	for(map<PII,int>::iterator it = parki.begin();it!=parki.end();it++){
		PII para = it->st;
		int a = para.st; int b = para.nd;
		int x = glosy[a]+glosy[b]-it->nd;
		if(x<m && ((glosy[a]+glosy[b])>=m)) res--;
	}
	

	cout<<res<<endl;




	return 0;
}