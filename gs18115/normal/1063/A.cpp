#include<iostream>
#include<algorithm>
using namespace std;
char S[123456];
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    cin>>S;
    sort(S,S+N);
    cout<<S<<endl;
    return 0;
}