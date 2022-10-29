#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    if (n<6){
        cout<<-1<<endl;
    }else{
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl;
        cout<<"1 4"<<endl;
        cout<<"4 5"<<endl;
        cout<<"4 6"<<endl;
        for (int i=7;i<=n;i++)
            cout<<i<<' '<<4<<endl;
    }
    for (int i=2;i<=n;i++)
        cout<<1<<' '<<i<<endl;
    return 0;
}