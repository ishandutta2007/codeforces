#include <fstream>
#include <vector>

using namespace std;

const char iname[] = "input.txt";
const char oname[] = "output.txt";

ifstream f(iname);
ofstream g(oname);

int main() {
	int N, K; 
    f >> N; K = 2;

	int answer = 0;
	int auxN = N;

	while (auxN > 1) {
		++answer;
		if (auxN % K)
			auxN = auxN / K + 1;
		else
			auxN /= K;
	}

	g << answer << "\n";

	vector<int> a(N), b;
	for (int i = 0; i < N; ++i)
		a[i] = i + 1;

	for (int i = 1; i <= answer; ++i) {
		swap(a, b);
		vector<int>().swap(a);

		for (int j = 0; j < K; ++j) {

            if (j == 0) {
			    if (j < N % K)
				    g << N / K + 1 << " ";
			    else
				    g << N / K << " ";
            }

			for (int k = j; k < N; k += K) {
        		a.push_back(b[k]);
                if (j == 0) {
				    g << b[k] << " ";
                }
			}

			if (j == 0)
                g << "\n";
		}
	}
}