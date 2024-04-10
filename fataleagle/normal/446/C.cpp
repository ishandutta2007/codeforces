#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

const int MOD=1000000009;
const int sz=550;
int N, M, t;
int A[300001];
int F[300001];
int F2[300001];
int X[300001][2];

struct block
{
    int l, r;
    int sum;
    int s1, s2;
    void rebuild()
    {
        A[l]=(A[l]+s1)%MOD;
        A[l+1]=(A[l+1]+s2)%MOD;
        for(int i=l+2; i<=r; i++)
        {
            int tmp=s1+s2;
            if(tmp>=MOD)
                tmp-=MOD;
            A[i]+=tmp;
            if(A[i]>=MOD)
                A[i]-=MOD;
            s1=s2;
            s2=tmp;
        }
        s1=s2=0;
        long long suma=0;
        for(int i=l; i<=r; i++)
            suma+=A[i];
        sum=suma%MOD;
    }
    void update(int x, int y)
    {
        int p=max(l, x);
        int q=min(r, y);
        if(p==l && q==r)
        {
            s1=(s1+F[l-x+1])%MOD;
            s2=(s2+F[l-x+2])%MOD;
            sum=((sum+F2[r-x+1])%MOD-F2[l-x]+MOD)%MOD;
            return;
        }
        rebuild();
        long long suma=0;
        for(int i=p; i<=q; i++)
        {
            A[i]+=F[i-x+1];
            if(A[i]>=MOD)
                A[i]-=MOD;
            suma+=F[i-x+1];
        }
        sum=(sum+suma)%MOD;
    }
    int query(int x, int y)
    {
        int p=max(l, x);
        int q=min(r, y);
        if(p==l && q==r)
            return sum;
        rebuild();
        long long ret=0;
        for(int i=p; i<=q; i++)
            ret+=A[i];
        return ret%MOD;
    }
} blocks[300000/sz+50];

//#define BF
#ifdef BF
int B[300001];
void update(int x, int y)
{
    for(int i=x; i<=y; i++)
        B[i]=(B[i]+F[i-x+1])%MOD;
}
int query(int x, int y)
{
    int ret=0;
    for(int i=x; i<=y; i++)
        ret=(ret+B[i])%MOD;
    return ret;
}
#endif

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    F[0]=0;
    F[1]=1;
    for(int i=2; i<=300000; i++)
        F[i]=(F[i-2]+F[i-1])%MOD;
    for(int i=1; i<=300000; i++)
        F2[i]=(F[i]+F2[i-1])%MOD;
#ifdef BF
    N=300000, M=300000;
    for(int i=1; i<=N; i++)
        A[i]=((long long)i*31+1993)%1000000000;
#else
    scan(N);
    scan(M);
    for(int i=1; i<=N; i++)
        scan(A[i]);
#endif
#ifdef BF
    for(int i=1; i<=N; i++)
        B[i]=A[i];
#endif
    int last=-1, cur=-1;
    for(int i=1; i<=N; i++)
    {
        cur=i/sz;
        if(cur!=last)
        {
            if(last!=-1)
            {
                blocks[last].r=i-1;
                blocks[last].rebuild();
            }
            last=cur;
            blocks[cur].l=i;
        }
    }
    if(cur!=-1)
    {
        blocks[cur].r=N;
        blocks[cur].rebuild();
    }
    int a, b, c;
    for(t=0; t<M; t++)
    {
#ifdef BF
        a=(t&1)+1;
        b=((long long)t*8883+37)%N+1;
        c=((long long)t*1273+97)%N+1;
        if(b>c)
            swap(b, c);
#else
        scan(a);
        scan(b);
        scan(c);
#endif
        if(a==1)
        {
            X[t][0]=b;
            X[t][1]=c;
            int l=b/sz;
            int r=c/sz;
            for(int i=l+1; i<r; i++)
                blocks[i].update(b, c);
            blocks[l].update(b, c);
            if(l!=r)
                blocks[r].update(b, c);
#ifdef BF
            update(b, c);
#endif
        }
        else
        {
            int l=b/sz;
            int r=c/sz;
            int ans=0;
            for(int i=l+1; i<r; i++)
                ans=(ans+blocks[i].query(b, c))%MOD;
            ans=(ans+blocks[l].query(b, c))%MOD;
            if(l!=r)
                ans=(ans+blocks[r].query(b, c))%MOD;
#ifdef BF
            if(query(b, c)!=ans)
                printf("ERROR %d vs %d\n", query(b, c), ans);
#else
            print(ans);
            putchar('\n');
#endif
        }
    }
    return 0;
}