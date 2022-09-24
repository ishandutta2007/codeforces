#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,L,maxi;
char S[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>L;
    cin>>S;
    for(char c='a';c<='z';c++)
    {
        int cnt=0,lev=0;
        for(int i=0;i<N;i++)
        {
            if(S[i]==c)
                lev++;
            else
                lev=0;
            if(lev>=L)
            {
                lev=0;
                cnt++;
            }
        }
        maxi=max(maxi,cnt);
    }
    cout<<maxi<<endl;
    return 0;
}