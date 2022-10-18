#include <iostream>

using namespace std;

int GCD(int a,int b) {
    return b ? GCD(b,a%b) : a;
}

int main()
{
    int a,b,n,cur_player=0;
    cin>>a>>b>>n;
    while (1) {
        if (!cur_player) {
            int g = GCD(a,n);
            if (g > n) {break;}
            n-=g;
        }
        else {
            int g = GCD(b,n);
            if (g > n) {break;}
            n-=g;
        }
        cur_player=!cur_player;
    }
    cout<<!cur_player;
    return 0;
}