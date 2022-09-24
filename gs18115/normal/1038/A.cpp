#include<iostream>
using namespace std;
int N,i;
int K,mini;
char C;
int cnt[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for(i=0;i<N;i++)
    {
        cin>>C;
        cnt[C-65]++;
    }
    mini=N;
    for(i=0;i<K;i++)
        mini=min(mini,cnt[i]);
    cout<<mini*K<<endl;
    return 0;
}