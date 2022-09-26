#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
#define N 1010
const int inf=0x3f3f3f3f;
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
int n;
vector<int> X,Y;
struct Point{
	int x,y,d[5]; //U:1  D:2  R:3  L:4
}a[N]; 
vector<Point> p;
map<int,set<pair<int,int> > > mpx,mpy;
struct Union_Set{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	int Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return 0;
		f[fy]=fx;
		return 1;
	}
}S,tmp;
inline void Get(Point &t){
	int x=t.x,y=t.y;
	if(mpx.count(x)){
		auto suf=mpx[x].upper_bound({y,inf});
		auto pre=mpx[x].lower_bound({y,0});
		if(suf!=mpx[x].end()){
			t.d[1]=suf->second;
		}
		if(pre!=mpx[x].begin()){
			t.d[2]=(--pre)->second;
		}
	}
	if(mpy.count(y)){
		auto suf=mpy[y].upper_bound({x,inf});
		auto pre=mpy[y].lower_bound({x,0});
		if(suf!=mpy[y].end()){
			t.d[3]=suf->second;
		}
		if(pre!=mpy[y].begin()){
			t.d[4]=(--pre)->second;
		}
	}
}
inline int Abs(int x){
	return x>=0?x:-x;
}

bool check(int dis){
	int tot=n;
	S.init(n);
	auto near = [&](Point p,int k)->bool{
		if(!k)return false;
		return Abs(p.x-a[k].x)+Abs(p.y-a[k].y)<=dis;
		return true;
	};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=4;++j){
			if(near(a[i],a[i].d[j]))tot-=S.Merge(i,a[i].d[j]);
		}
	}
	if(tot>4)return false;
	for(auto t:p){
		tmp.init(4);
		int gu=0;
		for(int j=1;j<=4;++j){
			for(int k=j+1;k<=4;++k){
				if(t.d[j]&&t.d[k]&&S.getf(t.d[j])==S.getf(t.d[k])){
					tmp.Merge(j,k);
				}
			}
		}
		for(int j=1;j<=4;++j){
			if(!near(t,t.d[j]))continue;
			for(int k=j+1;k<=4;++k){
				if(near(t,t.d[k])){
					gu+=tmp.Merge(j,k);
				}
			}
		}
		if(tot-gu==1)return true;
	}
	return false;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read();
		X.push_back(a[i].x),Y.push_back(a[i].y);
		mpx[a[i].x].insert({a[i].y,i});
		mpy[a[i].y].insert({a[i].x,i});
	}
	for(auto x:X){
		for(auto y:Y){
			p.push_back({x,y,{0,0,0,0,0}});
		}
	}
	for(auto [x,s]:mpx){
		int las=-inf;
		for(auto [y,id]:s){
			if(las>-inf){
				p.push_back({x,(y+las)/2,{0,0,0,0,0}});
			}
			las=y;
		}
	} 
	for(auto [y,s]:mpy){
		int las=-inf;
		for(auto [x,id]:s){
			if(las>-inf){
				p.push_back({(x+las)/2,y,{0,0,0,0,0}});
			}
			las=x;
		} 
	}
	for(auto &t:p){
		Get(t);
	}
	for(int i=1;i<=n;++i){
		Get(a[i]);
	}
	int l=0,r=inf<<1,ans=-1;
	while(l<r){
		int mid=((ll)l+r)>>1;
		if(check(mid)){
			r=mid,ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",ans); 
	return 0;
}