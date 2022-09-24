#include<iostream>
using namespace std;
bool chk[123456][3];
int N,i,w1,w2,h1,h2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    cin>>w1>>h1;
    chk[0][0]=chk[0][1]=true;
    for(i=1;i<N;i++)
    {
        cin>>w2>>h2;
        if(chk[i-1][0])
        {
            if(w2<=w1)
                chk[i][0]=true;
            if(h2<=w1)
                chk[i][1]=true;
        }
        if(chk[i-1][1])
        {
            if(w2<=h1)
                chk[i][0]=true;
            if(h2<=h1)
                chk[i][1]=true;
        }
        w1=w2;
        h1=h2;
    }
    if(chk[N-1][0]||chk[N-1][1])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}