#include <cstdio>

const int maxn=300000;
const long long mod=1e9+9;

struct fenv {
    long long tree[maxn+10];
    void add(int i, long long d) {
        for (;i<maxn+10;i|=(i+1)) tree[i]=tree[i]+d;
    }
    long long get(int i) {
        long long ans=0;
        for (;i>=0; i=(i&(i+1))-1) ans+=tree[i];
        return ans%mod;
    }
};

fenv t1, t2, t3;
long long fb[maxn+10], s[maxn+10];
int n, m, a, t, l, r;
char ss[20];

inline long long getfb(int i) {
    if (i>0) return fb[i];
    else if (i%2) return fb[-i];
    else return mod-fb[-i];
}

inline int geti() {
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    int ans=0;
    while (ch>='0'&&ch<='9') ans=(ans*10+ch-'0'), ch=getchar();
    return ans;
}

inline void puti(int i) {
    int j=0;
    while (i) ss[j]=(i%10)+'0', j++, i/=10;
    for (j--; j>=0; j--) putchar(ss[j]);
    putchar('\n');
}

int main() {
    fb[1]=fb[2]=1;
    for (int i=3; i<maxn+10; i++) fb[i]=(fb[i-1]+fb[i-2])%mod;
    n=geti(), m=geti();
    for (int i=1, sum=0; i<=n; i++) a=geti(), sum=(sum+a)%mod, s[i]=sum;
    for (int i=0; i<m; i++) {
        t=geti(), l=geti(), r=geti();
        if (t==1) {
            long long c=getfb(2-l), d=getfb(3-l);
            t1.add(l, c);
            t2.add(l, d);
            t3.add(l, -1);
            t1.add(r, -c);
            t2.add(r, -d);
            t3.add(r, fb[r-l+3]);
        } else {
            puti((int) (((t3.get(r)+t1.get(r)*fb[r]+t2.get(r)*fb[r+1]-t3.get(l-1)-t1.get(l-1)*fb[l-1]-t2.get(l-1)*fb[l]+s[r]-s[l-1])%mod+mod)%mod));
        }
    }
    return 0;
}