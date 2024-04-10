#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int a1, a2, a3, a4;
    cin>>a1>>a2>>a3>>a4;
    if(abs(a3 - a4) > 1){
        cout<<-1<<endl;
    }else if(a3 < a4){
        if(a1 < a4 || a2 < a4){
            cout<<-1<<endl;
        }else{
            int n4 = a1 - a4 + 1;
            int n7 = a2 - a4 + 1;
            a4 -= 2;
            cout<<'7';
            while(n4--)cout<<'4';
            while(a4--)cout<<"74";
            while(n7--)cout<<'7';
            cout<<'4';
        }
    }else if(a3 > a4){
        if(a1 < a3 || a2 < a3){
            cout<<-1<<endl;
        }else{
            int n4 = a1 - a3 + 1;
            int n7 = a2 - a3 + 1;
            a3--;
            while(n4--)cout<<'4';
            while(a3--)cout<<"74";
            while(n7--)cout<<'7';
        }
    }else{
        if(min(a1, a2) < a3 || max(a1, a2) < a3 + 1){
            cout<<-1<<endl;
        }else if(a1 >= a3 + 1){
            int n4 = a1 - a4;
            int n7 = a2 - a4 + 1;
            a4--;
            while(n4--)cout<<'4';
            while(a4--)cout<<"74";
            while(n7--)cout<<'7';
            cout<<'4';
        }else{
            int n4 = a1 - a4 + 1;
            int n7 = a2 - a4;
            a4--;
            cout<<'7';
            while(n4--)cout<<'4';
            while(a4--)cout<<"74";
            while(n7--)cout<<'7';
        }
    }
}