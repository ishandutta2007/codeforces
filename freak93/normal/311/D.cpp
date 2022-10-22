#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int kModulo = 95542721;
const int kPeriod = 48;
class SegmentTree {
  public:
    SegmentTree(const int &size) {
        for (size_ = 1; size_ < size; size_ *= 2);
        data_ = vector< vector<int> >(2 * size_, vector<int>(kPeriod, 0));
        lazy_ = vector<int>(2 * size_, 0);
    }

    void set(const int &position, int value) {
        for (int i = 0; i < kPeriod; ++i) {
            data_[position + size_][i] = value;
            value = (((1LL * value * value) % kModulo) * value) % kModulo;
        }

        for (int i = (position + size_) / 2; i > 0; i /= 2)
            update(i);
    }

    int query(int left, int right) const {
        return query(1, 0, size_, left, right, 0);
    }

    void pow(int left, int right) {
        pow(1, 0, size_, left, right);
    }

  private:
    void update(int node) {
        for (int i = 0; i < kPeriod; ++i)
            data_[node][i] = (data_[node * 2][(i + lazy_[node * 2]) % kPeriod] + 
                             data_[node * 2 + 1][(i + lazy_[node * 2 + 1]) % kPeriod]) % kModulo;
    }

    int query(int node, int begin, int end, int left, int right, int lazy) const {
        if (left <= begin and end <= right)
            return data_[node][(lazy + lazy_[node]) % kPeriod];
        int mid = (begin + end) / 2;

        int answer = 0;
        if (left < mid)
            answer += query(node * 2, begin, mid, left, right, lazy + lazy_[node]);
        if (mid < right)
            answer += query(node * 2 + 1, mid, end, left, right, lazy + lazy_[node]);
        return answer % kModulo;
    }

    void pow(int node, int begin, int end, int left, int right) {
        if (left <= begin and end <= right) {
            ++lazy_[node];
            return;
        }

        int mid = (begin + end) / 2;
        if (left < mid)
            pow(node * 2, begin, mid, left, right);
        if (mid < right)
            pow(node * 2 + 1, mid, end, left, right);
        update(node);
    }

    int size_;

    vector< vector<int> > data_;
    vector<int> lazy_;
};

int main() {
    cin.sync_with_stdio(false);
    int N; cin >> N;

    SegmentTree S(N);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        S.set(i, x);
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type, left, right; cin >> type >> left >> right;
        --left;

        if (type == 1)
            cout << S.query(left, right) << "\n";
        else
            S.pow(left, right);
    }
}