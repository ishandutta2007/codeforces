#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    long long int x;
    while(t--){
        cin>>x;
        long long int k = 1;
        bool found = false;
        for(; k < 31634; k++){
            long long int tmp = x + k*k;
            long long int n = sqrt(double(tmp));
            if(n*n != tmp)continue;
            long long int m = floor(double(n)/double(k));
            if(m*(k+1) > n){
                cout<<n<<" "<<m<<endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout<<-1<<endl;
        }
    }
}