#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int mn[100005],mx[100005],n,sss=0;
int main(){
//	freopen("cf.in","r",stdin);
//	freopen("cf2.out","w",stdout);
	long long ans=0;
	scanf("%d",&n);
	for(int i=1,l,x;i<=n;i++){
		scanf("%d",&l);
		int minn=0x3f3f3f3f,maxx=0,flag=1,y=-1;
		while(l--){
			scanf("%d",&x),minn=min(minn,x),maxx=max(maxx,x);
			if(~y){
				flag=(flag&&(x<=y));
			}
			y=x;
		}
		if(flag)mn[++sss]=minn,mx[sss]=maxx;
		else ans++;
	}
	ans=ans*n*2-ans*ans;
	//cout<<ans<<endl;
	sort(mn+1,mn+sss+1);
	sort(mx+1,mx+sss+1);
	for(int i=1,j=1;i<=sss;i++){
		while(mn[j]<mx[i]&&j<=sss)j++;
		if(j>0)j--;
		ans+=j;
		//cout<<i<<' '<<j<<endl;
	}
	cout<<ans;
}
/*
20
3 6 6 8 
5 1 1 4 4 7 
1 8 
2 0 6 
3 6 0 8 
1 0 
2 2 2 
5 0 9 3 6 3 
5 7 2 8 0 0 
2 2 0 
5 7 9 8 9 1 
4 2 0 1 8 
1 4 
1 8 
1 0 
5 0 3 4 4 9 
2 7 5 
2 5 7 
3 2 0 5 
1 4 
out:354
20
1 8 
1 0 
2 2 2 
2 2 0 
1 4 
1 8 
1 0 
2 7 5 
1 4 
0 0 0 2 4 4 5 8 8
0 0 2 2 4 4 7 8 8
0 0 3 3 4 4 7 7 7
319
*/