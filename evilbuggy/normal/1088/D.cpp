#include <bits/stdc++.h>

using namespace std;

int query(int a, int b){
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    int tmp;
    cin>>tmp;
    return tmp;
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int flag = query(0,0);
    int a = 0, b = 0;
    int tmp;

    for(int i = 29; i >= 0; i--){
        if(flag == 0){
            tmp = query(a|(1<<i), b);
            if(tmp == -1){
                a |= (1<<i);
                b |= (1<<i);
            }
        }else if(flag == 1){
            tmp = query(a|(1<<i), b|(1<<i));
            if(tmp == -1){
                a |= (1<<i);
                flag = query(a, b);
            }else{
                tmp = query(a|(1<<i), b);
                if(tmp == -1){
                    a |= (1<<i);
                    b |= (1<<i);
                }
            }
        }else{
            tmp = query(a|(1<<i), b|(1<<i));
            if(tmp == 1){
                b |= (1<<i);
                flag = query(a, b);
            }else{
                tmp = query(a|(1<<i), b);
                if(tmp == -1){
                    a |= (1<<i);
                    b |= (1<<i);
                }
            }
        }
    }
    cout<<"! "<<a<<" "<<b<<endl;
    fflush(stdout);
}