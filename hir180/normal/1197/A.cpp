#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int t;
int main(){
    cin >> t;
    while(t--){
        vector<int>vec;
        int n; scanf("%d",&n); rep(i,n){int x; scanf("%d",&x); vec.push_back(x);}
        int lb = 0,ub = 100005;
        sort(vec.begin(),vec.end());
        while(ub-lb > 1){
            int mid = (lb+ub)/2;
            if(vec[vec.size()-2] >= mid+1 && vec.size()-2 >= mid) lb = mid;
            else ub = mid;
        }
        cout<<lb<<endl;
    }
}