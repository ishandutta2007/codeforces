#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	int ans=1e9,ansi;
	for(int i = 0;i<n;i++){
		int s,d;
		scanf("%d %d",&s,&d);
		while(s<t)
		s+=d;
		if(s<ans){
			ans=s;
			ansi=i+1;
		}
	}
	printf("%d\n",ansi);
}