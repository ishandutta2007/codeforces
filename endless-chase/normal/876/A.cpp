
 #include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ac,ab,bc;
    cin>>n>>ab>>ac>>bc;
    int mn=min(ab,min(ac,bc));
    if(ac==mn or ab==mn)
    cout<<(n-1)*mn;
    else if(n>=2)
    cout<<min(ab,ac)+(n-2)*mn;
    else
    cout<<"0";
    return 0;
}