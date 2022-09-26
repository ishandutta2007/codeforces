#include<bits/stdc++.h>
using namespace std;
#define N 505
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,a[N],b[N],p[N];
vector<int> ans;
void Move(int x){
	ans.push_back(x);
	swap(a[x+1],a[x+2]);
	swap(a[x],a[x+1]);
}
mt19937 rnd(time(0));
bool check(){
	ans.clear();
	for(int i=1;i<=n-2;++i){
		int mn=1e9+233,u=-1;
		for(int j=i;j<=n;++j){
			if(a[j]<mn||(a[j]==mn&&rnd()&1))mn=a[j],u=j;
		}
		while(u>i+1){
			u-=2;
			Move(u);
		}
		if(u==i+1){
			Move(i),Move(i);
		}
	}
	return a[n-1]<=a[n];
}
void Output(){	
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
void Solve(){
	bool same=false;
	for(int i=1;i<=n;++i){
		a[i]=b[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i]==a[j]){
				same=true;break;
			}
		}
	}
	if(same){
		while(!check())memcpy(a,b,sizeof(a));
	}
	else if(!check()){
		printf("-1\n");
		return;
	}
	Output();
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}