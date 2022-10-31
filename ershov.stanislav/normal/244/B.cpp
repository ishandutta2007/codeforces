#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, a, res=0;
    cin >> n;
    vector<int> numbers;
    for (int i=1; i<10; i++) {
        int a = i;
        for (int k=1; k<10; k++) {
            numbers.push_back(a);
            a*=10;
            a += i;
        }
    }
    for (int i=0; i<9; i++) {
        for (int j=i+1; j<10; j++) {
            int b=2;
            for (int k=2; k<10; k++) {
                b*=2;
                for (int m=i ? 1 : b/2; m<b-1; m++) {
                    int a=0, c=m, d=b/2;
                    for (int l=0; l<k; l++) {
                        a*=10;
                        a += c&d ? j : i;
                        d/=2;
                    }
                    numbers.push_back(a);
                }
            }
        }
    }
    numbers.push_back(1000000000);
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] <= n) res++;
    }
    cout << res;
    return 0;
}