#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> l,r;
long long area[1005];
int turn[1005];
int main(){
    cin>>n;
    int temp;
    for (int x=3;x<=n;x++){
        cout<<"2 1 2 "<<x<<endl;
        cin>>temp;
        if (temp==1) l.push_back(x);
        else r.push_back(x);
    }

    for (int x=3;x<=n;x++){
        cout<<"1 1 2 "<<x<<endl;
        cin>>area[x];
    }

    sort(l.begin(),l.end(),[](int i,int j){
        return area[i]>area[j];
    });

    sort(r.begin(),r.end(),[](int i,int j){
        return area[i]>area[j];
    });

    if (!l.empty()){
        turn[l[0]]=0;
        for (int x=1;x<l.size();x++){
            cout<<"2 1 "<<l[0]<<" "<<l[x]<<" "<<endl;
            cin>>turn[l[x]];
        }
    }

    if (!r.empty()){
        turn[r[0]]=0;
        for (int x=1;x<r.size();x++){
            cout<<"2 1 "<<r[0]<<" "<<r[x]<<" "<<endl;
            cin>>turn[r[x]];
        }
    }

    sort(l.begin(),l.end(),[](int i,int j){
        if (turn[i]!=turn[j]) return turn[i]<turn[j];
        else return area[i]*turn[i]>area[j]*turn[j];
    });

    sort(r.begin(),r.end(),[](int i,int j){
        if (turn[i]!=turn[j]) return turn[i]<turn[j];
        else return area[i]*turn[i]>area[j]*turn[j];
    });

    cout<<"0 ";
    cout<<"1 ";
    for (int x=0;x<r.size();x++) cout<<r[x]<<" ";
    cout<<"2 ";
    for (int x=0;x<l.size();x++) cout<<l[x]<<" ";
    cout<<endl;
}