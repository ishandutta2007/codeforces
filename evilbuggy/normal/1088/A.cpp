#include <bits/stdc++.h>

using namespace std;

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin>>x;
    for(int a = 1; a <= x; a++){
        for(int b = 1; b <= x; b++){
            if(a%b == 0 && a < b*x && a*b > x){
                cout<<a<<" "<<b<<endl;
                exit(0);
            }
        }
    }
    cout<<-1<<endl;
}