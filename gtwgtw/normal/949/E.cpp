#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define pb push_back
#define mk make_pair
#define REP(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define se second
#define fi first

int n;
VI a;
int pw3[20];

PII dfs(int x,VI b){

//	for(auto x:b) printf("%d ",x); puts("");

	if(x>=18){
		if(b.size()==1&&b[0]==0) return PII(0,0);
		if(b.size()) return PII(1e9,1e9);
		return PII(0,0);
	}

	VI c;
	int fg=0;
	for(auto x:b) if(x&1){
		fg=1;
		break;
	}

	if(!fg){
		for(auto x:b) c.pb(x/2);
		return dfs(x+1,c);
	}else{
		c.clear();
		PII dd;


		for(auto x:b){
			if(x%2==0){
				c.pb(x/2);
			}else{
				c.pb((x-1)/2);
			}
		}
		int sz=unique(c.begin(),c.end())-c.begin();
		c.resize(sz);
		unique(c.begin(),c.end());
		dd=dfs(x+1,c);
		PII res=mk(dd.fi+1,dd.se+pw3[x]);

		c.clear();
		for(auto x:b){
			if(x%2==0){
				c.pb(x/2);
			}else{
				c.pb((x+1)/2);
			}
		}
		sz=unique(c.begin(),c.end())-c.begin();
		c.resize(sz);
		dd=dfs(x+1,c);
		PII res2=mk(dd.fi+1,dd.se+pw3[x]+pw3[x]);
		if(res2.fi<res.fi) res=res2;

		return res;
	}
}

int main(){
    scanf("%d",&n);
    REP(i,1,n){
        int x;
        scanf("%d",&x);
        a.pb(x);
    }
    sort(a.begin(),a.end());
    int sz=unique(a.begin(),a.end())-a.begin();
    a.resize(sz);
    *pw3=1;
    for(int i=1;i<=17;i++) pw3[i]=pw3[i-1]*3;
    PII res=dfs(0,a);
	printf("%d\n",res.fi);

	int t=0;
	while(res.se){
		if(res.se%3){
			if(res.se%3==1){
				printf("%d\n",1<<t);
			}else{
				printf("%d\n",-1<<t);
			}
		}
		t++;
		res.se/=3;
	}
    return 0;
}