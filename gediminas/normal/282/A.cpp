#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 0;
    while(n--){
        char c;
        cin >> c >> c;
        if(c=='-')
            x--;
        else
            x++;
            cin >> c;
    }
    cout << x;

    return 0;
}