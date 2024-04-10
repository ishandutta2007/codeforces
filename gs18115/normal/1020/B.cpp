#include<iostream>
#include<algorithm>
using namespace std;
const int MAXV=1010;
bool chk[MAXV];
int i,N;
int P[MAXV];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>P[i];
        P[i]--;
    }
    for(i=0;i<N;i++)
    {
        fill(chk,chk+1010,false);
        int j=i;
        while(!chk[j])
        {
            chk[j]=true;
            j=P[j];
        }
        cout<<j+1<<' ';
    }
    cout<<endl;
    return 0;
}