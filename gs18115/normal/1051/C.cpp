#include<iostream>
using namespace std;
typedef long long LL;
LL chk[123],A[123];
bool flag,flag2;
char P='A';
LL i,N,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        chk[A[i]]++;
    }
    for(i=0;i<103;i++)
    {
        if(chk[i]==1)
            cnt++;
        else if(chk[i]>2)
            flag=1;
    }
    if(!flag&&(cnt&1)==1)
        cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(i=0;i<N;i++)
        {
            if(chk[A[i]]==1)
            {
                cout<<(flag2?'A':'B');
                flag2=!flag2;
            }
            else if(chk[A[i]]==2)
                cout<<'A';
            else
            {
                if(flag&&(cnt&1)==1)
                {
                    cout<<(flag2?'A':'B');
                    flag=false;
                    flag2=!flag2;
                    P=flag2?'A':'B';
                }
                else
                    cout<<P;
            }
        }
    }
    cout<<endl;
    return 0;
}