#include <iostream>
using namespace std;

int main()
{
    string cur = "",q;
    int n,i,k;
    cin >> n;
    while (n--) {
        cin >> q;
        if (q == "pwd") {
            cout << cur+"/" << endl;
        } else {
            cin >> q;
            if (q[0] == '/') cur = q;
            else cur += "/"+q;
        }

        while((k=cur.find('.'))!=-1){
            i=++k;
            while(cur[i--]!='/');
            while(i>=0 && cur[i]!='/')
                --i;
            cur.erase(i,k-i+1);
        }
    }

    return 0;
}