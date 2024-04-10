#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
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
int n,a[N],T,cnt;
set<int> s;
int main(){
	T=read();
	while(T--){
		s.clear();
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=read();
			if(!(x&1))s.insert(x);
		}
		while(!s.empty()){
			int tmp=(*--s.end());
			s.erase(--s.end());
			tmp>>=1;ans++;
			if(tmp&1)continue;
			s.insert(tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}