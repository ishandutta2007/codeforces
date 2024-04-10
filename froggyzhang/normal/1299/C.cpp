#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000100
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
int n,top;
ll a[N];
pair<ll,int> st[N]; 
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	st[++top]=make_pair(a[1],1);
	for(int i=2;i<=n;++i){
		ll now=a[i];
		int cnt=1;
		while(top&&st[top].first*cnt>now*st[top].second){
			cnt+=st[top].second;
			now+=st[top].first;
			--top;
		}
		st[++top]=make_pair(now,cnt);
	}
	for(int i=1;i<=top;i++){
		int tot=st[i].second;
		for(int j=1;j<=tot;j++){
			printf("%.10lf\n",st[i].first*1.0/tot);
		}
	}
	return 0;
}