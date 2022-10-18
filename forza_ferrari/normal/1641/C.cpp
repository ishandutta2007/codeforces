#include<iostream>
#include<cstdio>
using namespace std;
int n,m,bin[200001],pos[200001];
inline int anc(int k)
{
    if(bin[k]==-1)
        return k;
    return bin[k]=anc(bin[k]);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i)
        bin[i]=pos[i]=-1;
    while(m--)
    {
        int opt;
        cin>>opt;
        if(opt==0)
        {
            int l,r,x;
            cin>>l>>r>>x;
            if(x==0)
            {
                l=anc(l-1);
                for(r=anc(r);r>l;r=anc(r-1))
                {
                    bin[r]=l;
                    pos[l]=max(pos[r],pos[l]);
                }
            }
            else
                pos[anc(r)]=max(pos[anc(r)],l-1);
        }
        if(opt==1)
        {
            int x;
            cin>>x;
            if(anc(x)^x)
                cout<<"NO\n";
            else if((~pos[x])&&anc(pos[x])==anc(x-1))
                cout<<"YES\n";
            else
                cout<<"N/A\n";
        }
    }
    return 0;
}