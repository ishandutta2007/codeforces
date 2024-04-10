#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,i;
LL gl,wl,st,tm;
LL minst,st2,P;
LL L[1234567],gen[1234567];
char S[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>L[i];
    cin>>S;
    for(i=0;i<N;i++)
    {
        if(S[i]=='W')
        {
            wl+=L[i];
            st+=L[i];
            tm+=3*L[i];
        }
        else if(S[i]=='G')
        {
            gl+=L[i];
            st+=L[i];
            tm+=5*L[i];
        }
        else
        {
            tm+=L[i];
            st-=L[i];
            if(st<0)
            {
                if(wl>0)
                    tm-=st*3;
                else
                    tm-=st*5;
                st=0;
            }
        }
    }
    minst=st2=st;
    for(i=N;i-->0;)
    {
        if(S[i]=='W')
            st2-=L[i];
        else if(S[i]=='G')
        {
            st2-=L[i];
            P=min({st2+L[i],minst,L[i]*2});
            tm-=2*P;
            st-=P;
            minst-=P;
            gen[i]=P;
        }
        else
            st2+=L[i];
        minst=min(minst,st2);
    }
    minst=st2=st;
    for(i=N;i-->0;)
    {
        if(S[i]=='W')
        {
            st2-=L[i];
            P=min({st2+L[i],minst,L[i]*2});
            tm-=P;
            st-=P;
            minst-=P;
        }
        else if(S[i]=='G')
            st2-=L[i]-gen[i];
        else
            st2+=L[i];
        minst=min(minst,st2);
    }
    cout<<tm<<endl;
    return 0;
}