import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        char[] arr = in.next().toCharArray();
        int answer = Integer.MAX_VALUE;
        int first = 0;
        int n = arr.length;
        while (arr[(first + n - 1) % n] == arr[0]) {
            first = (first + n - 1) % n;
            if (first == 0) break;
        }
        int oddOne = 0, evenOne = 0, allParts = 0;
        int current = first;
        int nowAt = 0;
        List<Integer> allSize = new ArrayList<Integer>();
        do {
            int next = current;
            int size = 0;
            while (arr[next] == arr[current]) {
                next = (next + 1) % n;
                ++size;
                if (next == first) break;
            }
            allSize.add(size);
            current = next;
        } while (current != first);
        int[] size = new int[allSize.size()];
        for (int i = 0; i < size.length; ++i) {
            size[i] = allSize.get(i);
        }
        int result = 0;
        first = 0;
        n = size.length;
        for (int i = 0; i < n; ++i) {
            if (size[i] > 1) {
                first = i;
                break;
            }
        }
        if (size[first] == 1) {
            out.println((n + 1) / 2);
            return;
        }
        current = first;
        answer = 0;
        do {
            int next = current;
            int currentSize = 0;
            while (size[next] == size[current]) {
                next = (next + 1) % n;
                ++currentSize;
                if (next == first) break;
            }
            if (size[current] > 1) {
                answer += currentSize;
            } else {
                answer += currentSize / 2;
            }
            current = next;
        } while (current != first);
        out.println(answer);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    }