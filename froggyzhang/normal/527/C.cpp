#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
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
int w,h,n,l,r;
char opt[3];
set<int> a,b;
multiset<int> f,g;
int main(){
	w=read(),h=read(),n=read();
	a.insert(0),b.insert(0);
	a.insert(w),b.insert(h);
	f.insert(w),g.insert(h);
	for(int i=1;i<=n;i++){
		scanf("%s",opt+1);
		int x=read();
		if(opt[1]=='V'){
			r=(*a.lower_bound(x));
			l=(*(--a.lower_bound(x)));
			f.erase(f.find(r-l));
			f.insert(r-x),f.insert(x-l);
			a.insert(x);
		}
		else{
			r=(*b.lower_bound(x));
			l=(*(--b.lower_bound(x)));
			g.erase(g.find(r-l));
			g.insert(r-x),g.insert(x-l);
			b.insert(x);
		}
		printf("%I64d\n",1LL*(*(--f.end()))*(*(--g.end())));
	}
	return 0;
}