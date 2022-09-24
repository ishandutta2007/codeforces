#include<iostream>
#include<iomanip>
using namespace std;
double D,m,M;
int N,i,A;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>m;
    M=m;
    for(i=0;i<N<<1;i++)
    {
        cin>>A;
        if(A==1)
        {
            cout<<-1<<endl;
            return 0;
        }
        m*=A;
        m/=A-1;
    }
    cout<<setprecision(12)<<m-M<<endl;
    return 0;
}