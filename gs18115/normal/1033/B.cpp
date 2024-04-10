#include<iostream>
using namespace std;
long long T,A,B,i;
bool flag;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>A>>B;
        if(A>B+1)
            cout<<"NO\n";
        else
        {
            flag=false;
            for(i=2;i*i<=A+B;i++)
            {
                if((A+B)%i==0)
                {
                    flag=true;
                    cout<<"NO\n";
                    break;
                }
            }
            if(!flag)
                cout<<"YES\n";
        }
    }
    cout<<endl;
    return 0;
}