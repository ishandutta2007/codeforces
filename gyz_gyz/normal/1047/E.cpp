#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
const int maxbuff = 1<<17;
char ibuff[maxbuff],obuff[maxbuff];
inline char Getchar(){
    static char *p1=ibuff,*p2=ibuff;
    if(p1 == p2) {
        p1 = ibuff;
        p2 = ibuff+fread(ibuff,1,maxbuff,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
}
  
int optr = 0;
inline void Putchar(char c) {
    if(optr == maxbuff) {fwrite(obuff,1,optr,stdout);optr = 0;}
    obuff[optr++] = c;
}
  
inline void Flush() {
    fwrite(obuff,1,optr,stdout);
}
  
template<class T>
    inline int read(T &x) {
        x = 0;
        char c = Getchar();
        if(c == EOF) return -1;
        for( ; (c < '0' || c > '9') && c != EOF ; c = Getchar());
        if(c == EOF) return -1;
        for( ; c >= '0' && c <= '9' ; c = Getchar()) x = x*10+c-'0';
        return 0;
    }
  
template<class T>
    inline void write(const T &x,int tag = 0) {
        if(!x) {
            if(!tag) Putchar(x+'0');
            return ;
        }
        write(x/10,1);
        Putchar(x%10+'0');
    }
  
template<class T>
    inline void writeln(const T &x) {
        write(x);Putchar('\n');
    }
  
template<class T>
    inline void writesp(const T &x) {
        write(x);Putchar(' ');
    }
int n,tot,x,y,f[N],fa[N],r[N],t[N],w[N];ll s[N];
ll gcd(ll x,ll y){
	if(!x)return y;return gcd(y%x,x);
}
int main(){
	read(n);
	rep(i,1,n)read(s[i]);
	rep(i,2,n)read(fa[i]);
	dep(i,n,1)s[fa[i]]+=s[i];
	rep(i,1,n){
		ll x=s[1]/gcd(s[i],s[1]);
		if(x<=n)r[x]++;
	}
	rep(i,1,n)if(r[i])rep(j,1,n/i)t[i*j]+=r[i];
	rep(i,1,n)if(t[i]==i)w[++tot]=i;
	dep(i,tot,1){f[i]=1;
		rep(j,i+1,tot)if(!(w[j]%w[i]))add(f[i],f[j]);
	}
	write(f[1]);Flush();
}