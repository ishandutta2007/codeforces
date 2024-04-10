#include <bits/stdc++.h>

using namespace std;

int lpf[1000005];

void prePro(){
    memset(lpf, 0, sizeof(lpf));
    for(int i = 2; i < 1000005; i++){
        if(lpf[i] == 0){
            for(int j = i; j < 1000005; j += i){
                if(lpf[j] == 0){
                    lpf[j] = i;
                }
            }
        }
    }
}

vector<int> pf;

void fillvec(int n){
    while(n > 1){
        int x = lpf[n];
        while(n%x == 0){
            n /= x;
        }
        pf.push_back(x);
    }
}

bool isPos(int x1, int x2){
    for(size_t i = 0; i < pf.size(); i++){
        if(x2 - x1 < pf[i] && x1 > pf[i])return true;
    }
    return false;
}

int findMin(int x1){
    int m = x1, ans = x1;
    while(m > 1){
        ans = min(ans, max(x1 - lpf[m], lpf[m]) + 1);
        m /= lpf[m];
    }
    return ans;
}

int main(){
    prePro();
    int x2;
    cin>> x2;
    fillvec(x2);
    int x0 = x2;
    for(int i = 2; i < x2; i++){
        if(isPos(i, x2)){
            x0 = min(x0, findMin(i));
        }
    }
    cout<<x0<<endl;
}