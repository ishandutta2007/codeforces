#include<iostream>
using namespace std;
int i,N,cnt;
char C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>C;
        if(C=='8')
            cnt++;
    }
    cout<<min(cnt,N/11)<<endl;
    return 0;
}