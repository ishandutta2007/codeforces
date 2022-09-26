#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000010
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
int n,a[N],bit[3][N],cnt,mx;
ll ans;
inline int lowbit(int x){
	return x&(-x);
}
void Add(int x,int p){
	while(x<=mx){
		bit[p][x]++;
		x+=lowbit(x);
	}
}
int Ask(int x,int p){
	if(!x)return 0;
	int ans=0;
	while(x){
		ans+=bit[p][x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	n=read();mx=1000001;
	for(int i=1;i<=n;i++){
		int l=read();
		for(int j=1;j<=l;j++){
			a[j]=read()+1;	
		}
		bool ok=true;
		for(int j=2;j<=l;j++){
			if(a[j]>a[j-1]){
				++cnt;
				ans+=2*i-1;
				ok=false;
				break;
			}
		}
		if(!ok)continue;
		ans+=2*cnt;
		ans+=Ask(a[1]-1,2);
		ans+=Ask(mx,1)-Ask(a[l],1);
		Add(a[1],1),Add(a[l],2);
		if(a[l]<a[1])++ans;
	}
	cout<<ans<<endl;
	return 0;
}