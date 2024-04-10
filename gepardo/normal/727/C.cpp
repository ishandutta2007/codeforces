#include <iostream>

using namespace std;

int arr[10000];

int main()
{
    int n; cin >> n;
    int ab, ac, bc;
    cout << "? 1 2" << endl;
    cin >> ab;
    cout << "? 2 3" << endl;
    cin >> bc;
    cout << "? 3 1" << endl;
    cin >> ac;
    int abc = (ab + ac + bc) / 2;
    arr[0] = abc - bc;
    arr[1] = abc - ac;
    arr[2] = abc - ab;
    for (int i = 3; i < n; i++)
    {
        int ax;
        cout << "? 1 " << i+1 << endl;
        cin >> ax;
        arr[i] = ax - arr[0];
    }
    cout << "!";
    for (int i = 0; i < n; i++) cout << " " << arr[i];
    cout << endl;
    return 0;
}