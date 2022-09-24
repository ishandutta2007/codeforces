#include<iostream>
using namespace std;
typedef long long LL;
LL T;
char S[1234567];
LL ss[1234567];
LL cnt[5];
LL i,sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>S;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(i=0;S[i];i++)
        {
            if(S[i]>47&&S[i]<58)
                ss[i]=0;
            else if(S[i]<'a')
                ss[i]=1;
            else
                ss[i]=2;
            cnt[ss[i]]++;
        }
        sz=i;
        if(cnt[0]>0&&cnt[1]>0&&cnt[2]>0)
            cout<<S;
        else if(cnt[0]>0)
        {
            if(cnt[1]>0)
            {
                if(cnt[0]>1)
                {
                    for(i=0;i<sz;i++)
                        if(S[i]<'A')
                            break;
                    S[i]='a';
                    cout<<S;
                }
                else
                {
                    for(i=0;i<sz;i++)
                        if(S[i]>'9')
                            break;
                    S[i]='a';
                    cout<<S;
                }
            }
            else if(cnt[2]>0)
            {
                if(cnt[0]>1)
                {
                    for(i=0;i<sz;i++)
                        if(S[i]<'a')
                            break;
                    S[i]='A';
                    cout<<S;
                }
                else
                {
                    for(i=0;i<sz;i++)
                        if(S[i]>'9')
                            break;
                    S[i]='A';
                    cout<<S;
                }
            }
            else
            {
                S[0]='A';
                S[1]='a';
                cout<<S;
            }
        }
        else if(cnt[1]>0)
        {
            if(cnt[2]>0)
            {
                if(cnt[1]>1)
                {
                    for(i=0;i<sz;i++)
                        if(S[i]<'a')
                            break;
                    S[i]='0';
                    cout<<S;
                }
                else
                {
                    for(i=0;i<sz;i++)
                        if(S[i]>'Z')
                            break;
                    S[i]='0';
                    cout<<S;
                }
            }
            else
            {
                S[0]='0';
                S[1]='a';
                cout<<S;
            }
        }
        else
        {
            S[0]='0';
            S[1]='A';
            cout<<S;
        }
        for(i=0;i<sz;i++)
            S[i]=0;
        cout<<'\n';
    }
    cout<<endl;
    return 0;
}