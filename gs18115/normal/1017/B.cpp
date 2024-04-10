#include<iostream>
using namespace std;
long long N;
char a[123456],b[123456];
long long sum[3][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>a;
    cin>>b;
    for(int i=0;i<N;i++)
        sum[a[i]-48][b[i]-48]++;
    cout<<sum[1][0]*sum[0][0]+sum[1][1]*sum[0][0]+sum[1][0]*sum[0][1];
    return 0;
}