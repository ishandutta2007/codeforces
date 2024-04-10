    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    int n,x,y,z,w;
    cin>>n;
    cout<<"YES\n";
    while(n--){
    cin>>x>>y>>z>>w;
    cout<<abs((x%2))*2+abs((y%2))+1<<"\n";
    }
    }