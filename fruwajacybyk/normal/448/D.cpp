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
#define max_n 100005

using namespace std;

lint n,m,k;

lint f(lint u){
	lint sum = 0;
	FOR(i,1,n+1){
		lint a = min(m,u/i);
		sum+=a;
		if(a==0) return sum;
	}
	return sum;

}





int main(){
	cin>>n>>m>>k;
	lint l = 0;
	lint p = n*m;

	while(p-l>1){
		lint sr = (l+p)/2;
		if(f(sr)>=k) p = sr;
		else l = sr;
	}
	if(f(l)>=k) cout<<l<<endl;
	else cout<<p<<endl;


	return 0;
}