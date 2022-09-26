#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
#define N 1000100
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
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
int pos[N],type[N],f[N],cnt,p[N];
int getf(int x){
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		f[i]=i;
		int l=read(),r=read();
		pos[l]=pos[r]=i;
		p[i]=l;
		type[l]=0,type[r]=1;
	}
	for(int i=1;i<=2*n;i++){
		int x=pos[i];
		if(type[i]==0){
			s.insert(make_pair(p[x],x));
		}
		else{
			it=s.lower_bound(make_pair(p[x],x));
			++it;
			int fx=getf(x);
			for(;it!=s.end();++it){
				int fy=getf(it->second);
				if(fx==fy){
					printf("NO\n");
					return 0;
				}
				f[fy]=fx;
				++cnt;
			}
			s.erase(s.find(make_pair(p[x],x)));
		}
	}
	if(cnt==n-1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}