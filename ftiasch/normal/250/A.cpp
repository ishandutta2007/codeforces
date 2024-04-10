#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    int size = 0;
    int negatives = 0;
    vector <int> answer;
    for (int i = 0; i < n; ++ i) {
        if (a[i] >= 0) {
            size ++;
        } else if (negatives < 2) {
            size ++;
            negatives ++;
        } else {
            answer.push_back(size);
            size = 1;
            negatives = 1;
        }
    }
    answer.push_back(size);
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < (int)answer.size(); ++ i) {
        printf("%d ", answer[i]);
    }
    puts("");
    return 0;
}