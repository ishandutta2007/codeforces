#include<iostream>
using namespace std;
char C[1234];
bool chk[1234];
int N,K,s,i,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    cin>>C;
    for(i=0;C[i];i++)
        chk[C[i]-'a'+1]=true;
    for(i=1;i<27&&cnt<K;i++)
    {
        if(chk[i])
        {
            cnt++;
            s+=i;
            i++;
        }
    }
    if(cnt<K)
        cout<<-1<<endl;
    else
        cout<<s<<endl;
    return 0;
}