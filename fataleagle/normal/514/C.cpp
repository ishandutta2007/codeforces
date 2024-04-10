#include <bits/stdc++.h>

using namespace std;

const int X=3;
const int MOD1=1000000021;
const int MOD2=100000009;
int P1[300001];
int P2[300001];

struct Hash
{
    int len, val1, val2;
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val1=(other.val1+1LL*P1[other.len]*val1)%MOD1;
        ret.val2=(other.val2+1LL*P2[other.len]*val2)%MOD2;
        return ret;
    }
    Hash operator- (const Hash& other) const
    {
        Hash ret;
        ret.len=len-other.len;
        ret.val1=val1-1LL*P1[len-other.len]*other.val1%MOD1;
        if(ret.val1<0)
            ret.val1+=MOD1;
        ret.val2=val2-1LL*P2[len-other.len]*other.val2%MOD2;
        if(ret.val2<0)
            ret.val2+=MOD2;
        return ret;
    }
    bool operator< (const Hash& other) const
    {
        if(len!=other.len)
            return len<other.len;
        if(val1!=other.val1)
            return val1<other.val1;
        return val2<other.val2;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val1==other.val1 && val2==other.val2;
    }
};

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<300001; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<300001; i++)
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

int N, M;
set<Hash> s;
char buf[6000001];
Hash F[6000001];
Hash R[6000001];

int main()
{
    init_hash();
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        scanf("%s", buf);
        int L=strlen(buf);
        for(int j=0; j<L; j++)
        {
            F[j].len=1, F[j].val1=F[j].val2=buf[j]-'a';
            if(j>0)
                F[j]=F[j-1]+F[j];
        }
        for(int j=L-1; j>=0; j--)
        {
            R[j].len=1, R[j].val1=R[j].val2=buf[j]-'a';
            if(j<L-1)
                R[j]=R[j]+R[j+1];
        }
        for(int j=0; j<L; j++)
        {
            for(int k=0; k<3; k++) if(buf[j]-'a'!=k)
            {
                Hash h;
                h.len=1, h.val1=h.val2=k;
                if(j>0)
                    h=F[j-1]+h;
                if(j<L-1)
                    h=h+R[j+1];
                s.insert(h);
            }
        }
    }
    for(int i=0; i<M; i++)
    {
        scanf("%s", buf);
        int L=strlen(buf);
        Hash h;
        h.len=1, h.val1=h.val2=buf[0]-'a';
        for(int j=1; j<L; j++)
        {
            Hash tmp;
            tmp.len=1, tmp.val1=tmp.val2=buf[j]-'a';
            h=h+tmp;
        }
        if(s.count(h))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}