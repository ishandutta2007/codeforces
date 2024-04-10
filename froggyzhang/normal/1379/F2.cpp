#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define N 200020
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
map<pair<int,int>,int> mp;
int n,m,q,ans[N];
struct QAQ{
	int x,y,type,id,val;
	bool operator <(const QAQ b)const{
		return x==b.x?type>b.type:x<b.x;
	}
}p[N];
bool cmp1(QAQ a,QAQ b){
	return a.x==b.x?a.type>b.type:a.x<b.x;
}
bool cmp2(QAQ a,QAQ b){
	return a.x==b.x?a.type<b.type:a.x>b.x;
}
struct BIT{
	int bit[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	void Clear(){
		memset(bit,0,sizeof(bit));
	}
	inline void Add(int x,int d){
		while(x<=m){
			bit[x]+=d;
			x+=lowbit(x);
		}
	}
	inline int Ask(int x){
		int ans=0;
		while(x){
			ans+=bit[x];
			x-=lowbit(x);
		}
		return ans;
	}
}B;
void CDQ(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	sort(p+l,p+mid+1,cmp1);
	sort(p+mid+1,p+r+1,cmp1);
	int j=l;
	for(int i=mid+1;i<=r;++i){
		while(j<=mid&&p[j].x<=p[i].x){
			if(p[j].type)B.Add(p[j].y,p[j].val);
			++j;
		}
		if(!p[i].type)ans[p[i].id]+=p[i].val*B.Ask(p[i].y);
	}
	for(int i=l;i<j;++i){
		if(p[i].type)B.Add(p[i].y,-p[i].val);
	}
	sort(p+l,p+mid+1,cmp2);
	sort(p+mid+1,p+r+1,cmp2);
	j=l;
	for(int i=mid+1;i<=r;++i){
		while(j<=mid&&p[j].x>=p[i].x){
			if(!p[j].type)B.Add(m-p[j].y+1,p[j].val);
			++j;
		}
		if(p[i].type)ans[p[i].id]+=p[i].val*B.Ask(m-p[i].y+1);
	}
	for(int i=l;i<j;++i){
		if(!p[i].type)B.Add(m-p[i].y+1,-p[i].val);
	}
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=q;++i){
		int x=read(),y=read();
		p[i].x=(x+1)>>1;
		p[i].y=(y+1)>>1;
		p[i].id=i;
		p[i].type=(x&1);
		p[i].val=(mp[make_pair(x,y)]&1?-1:1);
		++mp[make_pair(x,y)];
	}
	CDQ(1,q);
	for(int i=1;i<=q;++i){
		ans[i]+=ans[i-1];
	}
	for(int i=1;i<=q;++i){
		printf(ans[i]?"NO\n":"YES\n");
	}
	return 0;
}