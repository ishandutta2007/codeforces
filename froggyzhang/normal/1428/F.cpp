#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 500050
typedef long long ll;
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
ll now,ans;
char s[N];
pair<pair<int,int>,pair<ll,ll> > st[N];
ll Get(int p,int R){
	if(!top||p>=st[1].second.first)return 1LL*R*p;
	int l=1,r=top+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(p>=st[mid].second.first){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return st[ans-1].second.second+1LL*(R-st[ans-1].first.second)*p;
}
void Modify(int t,int z){
	bool flag=false;
	while(top&&st[top].second.first<=t)--top,flag=true;
	if(flag){
		++top;
		st[top]=make_pair(make_pair(st[top-1].first.second+1,z),make_pair(t,st[top-1].second.second+1LL*t*(z-st[top-1].first.second)));
	}
	for(int i=z+1;i<=z+t;++i){
		++top;
		st[top]=make_pair(make_pair(i,i),make_pair(z+t-i+1,st[top-1].second.second+z+t-i+1));
	}
	now=st[top].second.second;
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1,d=0;i<=n;++i){
		if(s[i]=='0'){
			if(top&&st[top].second.first==0)++st[top].first.second;
			else st[++top]=make_pair(make_pair(i,i),make_pair(0,now));
			d=0;
			ans+=now;
		}
		else{
			++d;
			ans+=1LL*d*(d+1)/2;
			ans+=Get(d,i-d);
			if(i==n||s[i+1]=='0'){
				Modify(d,i-d);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}