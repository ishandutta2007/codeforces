#include<iostream>
using namespace std;
int T,N,i,j;
char S[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>N;
        cin>>S;
        bool flag=false;
        for(i=0,j=N-1;i<j;i++,j--)
        {
            if(abs(S[i]-S[j])>0&&abs(S[i]-S[j])!=2)
            {
                cout<<"NO\n";
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<"YES\n";
    }
    cout<<endl;
    return 0;
}