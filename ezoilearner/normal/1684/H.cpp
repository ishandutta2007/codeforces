#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
 
typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second
 
inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
 
#define Maxn 1000010

int n,ones[Maxn],pos[6]; char s[Maxn];
vector<pii>ans; vector<int>vec;

int get(int l,int k){
	return vec[ones[l-1]+k-1];
}

void add(int l,int r){
	if(l<=r&&l>=1&&r<=n)
		ans.emplace_back(make_pair(l,r));
}

void solve(int l,int r,int y){
	int x=ones[r]-ones[l-1];
	if(x>11){
		int p=get(l,x/2);
		solve(l,p,y/2),solve(p+1,r,y/2);
		return;
	}
	if(x==y){
		rep(i,l,r) add(i,i); return;
	}
	if(y<=x*3/2){
		int p1=get(l,1),p2=get(l,2);
		rep(i,l,p1-1) add(i,i);
		if(p1+1==p2) add(p1,p2);
		else {
			add(p1,p1+1);
			rep(i,p1+2,p2) add(i,i);
		}
		return solve(p2+1,r,y-3);
	}
	if(x==8||x==10){
		int p=get(l,4);
		solve(l,p,8),solve(p+1,r,8);
	}
	if(x==9||x==4){
		int p=get(l,1);
		rep(i,l,p-1) add(i,i);
		add(p,p+2);
		solve(p+3,r,y-4-(s[p+1]-48)*2-(s[p+2]-48));
	}
	if(x==7){
		int p=get(l,3);
		solve(l,p,3),solve(p+1,r,8);
	}
}

void work(){
	scanf("%s",s+1);
	n=strlen(s+1),ans.clear(),vec.clear();
	rep(i,1,n){
		if(s[i]=='1') vec.emplace_back(i);
		ones[i]=ones[i-1]+(s[i]=='1');
	}
	if (!ones[n]) goto PR;
	if (ones[n]==5){
		rep(p,1,5) pos[p]=get(1,p);
		if (pos[5]-pos[1]==4){
			int l=pos[1],r=pos[5];
			add(1,l-1),add(l,r-1),add(r,r),add(r+1,n);
		} // 1111 + 1
		rep(p,1,4) if(pos[p]+1!=pos[p+1]){
			rep(i,1,pos[p]-1) add(i,i);
			add(pos[p],pos[p]+2);
			rep(i,pos[p]+3,n) add(i,i);
			break;
		} // 100 + 1+1+1+1 or 101 + 1+1+1
		goto PR;
	}
	else {
		int y=1;
		while(y<ones[n]) y<<=1;
		solve(1,n,y);
	}
	PR:;
	if(!ans.size()) puts("-1");
	else {
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d %d\n",x.FR,x.SE);
	}
}

int main(){
	int T; rd(T);
	while(T--) work();
}