#include <bits/stdc++.h>

using namespace std;

const int HASH_MAXN=300000;
const int X=129;
const int MOD1=1000000009;
const int MOD2=1000000021;
int P1[HASH_MAXN];
int P2[HASH_MAXN];

struct Hash
{
    int len, val0, val1;
    Hash()
    {
        //
    }
    Hash(int val):
        len(1),
        val0(val),
        val1(val)
    {
        //
    }
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val0=(other.val0+1LL*P1[other.len]*val0)%MOD1;
        ret.val1=(other.val1+1LL*P2[other.len]*val1)%MOD2;
        return ret;
    }
    Hash operator- (const Hash& other) const
    {
        Hash ret;
        ret.len=len-other.len;
        ret.val0=val0-1LL*P1[len-other.len]*other.val0%MOD1;
        if(ret.val0<0)
            ret.val0+=MOD1;
        ret.val1=val1-1LL*P2[len-other.len]*other.val1%MOD2;
        if(ret.val1<0)
            ret.val1+=MOD2;
        return ret;
    }
    bool operator< (const Hash& other) const
    {
        if(len!=other.len)
            return len<other.len;
        if(val0!=other.val0)
            return val0<other.val0;
        return val1<other.val1;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val0==other.val0 && val1==other.val1;
    }
    bool operator!= (const Hash& other) const
    {
        return !(*this==other);
    }
};

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

static int _hash_initialized=(init_hash(), 0);

int N, M;
char S[300001];
char T[300001];
Hash PS[26][300001];
Hash PT[26][300001];
vector<int> occ[26];
int last[26];

int main()
{
    scanf("%d%d%s%s", &N, &M, S+1, T+1);
    for(int i=0; i<26; i++)
    {
        for(int j=1; j<=N; j++)
        {
            Hash tmp;
            tmp.len=1;
            if(S[j]-'a'==i)
                tmp.val0=tmp.val1=1;
            else
                tmp.val0=tmp.val1=2;
            PS[i][j]=PS[i][j-1]+tmp;
        }
        for(int j=1; j<=M; j++)
        {
            Hash tmp;
            tmp.len=1;
            if(T[j]-'a'==i)
                tmp.val0=tmp.val1=1;
            else
                tmp.val0=tmp.val1=2;
            PT[i][j]=PT[i][j-1]+tmp;
        }
    }
    for(int i=1; i<=N; i++)
        occ[S[i]-'a'].push_back(i);
    for(int i=1; i<=M; i++)
        last[T[i]-'a']=i;
    int opp[26];
    vector<int> ans;
    for(int i=1; i<=N-M+1; i++)
    {
        memset(opp, -1, sizeof opp);
        int r=i+M-1;
        for(int j=0; j<26; j++)
        {
            auto it=lower_bound(occ[j].begin(), occ[j].end(), i);
            if(it==occ[j].end())
                continue;
            int pos=*it;
            if(pos>r)
                continue;
            int k=T[pos-i+1]-'a';
            if(opp[j]!=-1 && opp[j]!=k)
                goto fail;
            opp[j]=k;
            if(opp[k]!=-1 && opp[k]!=j)
                goto fail;
            opp[k]=j;
        }
        for(int j=0; j<26; j++) if(last[j])
        {
            int k=S[i+last[j]-1]-'a';
            if(opp[j]!=-1 && opp[j]!=k)
                goto fail;
            opp[j]=k;
            if(opp[k]!=-1 && opp[k]!=j)
                goto fail;
            opp[k]=j;
        }
        for(int j=0; j<26; j++)
        {
            if(opp[j]==-1)
            {
                if(PS[j][i+M-1]-PS[j][i-1]!=PT[j][M])
                    goto fail;
            }
            else
            {
                if(PS[opp[j]][i+M-1]-PS[opp[j]][i-1]!=PT[j][M])
                    goto fail;
            }
        }
        ans.push_back(i);
        fail:;
    }
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d ", it);
    printf("\n");
    return 0;
}