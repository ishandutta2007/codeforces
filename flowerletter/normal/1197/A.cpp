#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n,a[MAXN],max1,max2;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n,max1=max2=0;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    for(int i=1;i<=n;i++){
	    	if(a[i]>=max1) max2=max1,max1=a[i];
	    	else if(a[i]>=max2) max2=a[i];
	    }
	    cout<<min(max2-1,n-2)<<endl;
	}
	return 0;
}