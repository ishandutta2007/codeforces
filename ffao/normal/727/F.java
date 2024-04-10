import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public static PriorityQueue queue;

        public static int solutionBinarySearch(long[] values, long n) {
            int start = 0;
            int end = values.length - 1;

            while (start <= end) {
                int mid = (start + end) / 2;

                if (values[mid] >= n) {
                    end = mid - 1;
                } else if (values[mid] < n) {
                    start = mid + 1;
                }
            }

            return start;
        }

        public static long binarySearch(long[] values, int removed) {
            long low = -1000000000000L;
            long high = 1000000000000L;

            while (low <= high) {
                long mid = (low + high) / 2;

                if (!verify(values, removed, mid)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return high;
        }

        public static boolean verify(long[] values, int removed, long target) {
            //If we can remove "removed" number of values from array values, can the minimum prefix sum be greater than or equal to target?'

            queue.clear();

            int count = 0;
            long sum = 0;
            for (int i = 0; i < values.length; i++) {
                sum += values[i];
                queue.add(values[i]);
                while (sum < target) {
                    if (!queue.isEmpty()) {
                        sum -= queue.remove();
                        count++;
                    } else return false;
                }
            }

            return count <= removed;
        }

        public void solve(int testNumber, Parser in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            long[] values = new long[n];
            queue = new PriorityQueue(n);

            for (int i = 0; i < n; i++) {
                values[i] = in.nextInt();
            }

            long[] dp = new long[n + 1]; //dp[i] represents the maximum minimum prefix sum you can obtain with i removed objects

            for (int i = 0; i < n + 1; i++) {
                dp[i] = binarySearch(values, i);
            }
            dp[n] = 0;

            for (int i = 0; i < m; i++) {
                long q = in.nextLong();
                out.println(solutionBinarySearch(dp, -q));

			/*
            int index = Arrays.binarySearch(dp, -q);

			if (index >= 0) {
				w.println(index);
			} else {
				w.println(-index - 1);
			}*/
            }
        }

        public class PriorityQueue {
            private int size = 0;
            private long[] elements;

            public PriorityQueue(int capacity) {
                elements = new long[capacity];
            }

            public boolean isEmpty() {
                return size == 0;
            }

            public void add(long element) {
                elements[size] = element;
                shiftUp(size++);
            }

            public void shiftUp(int index) {
                long value = elements[index];
                while (index != 0) {
                    int parent = (index - 1) >>> 1;
                    long parentValue = elements[parent];
                    if (parentValue <= value) {
                        elements[index] = value;
                        return;
                    }
                    elements[index] = parentValue;
                    index = parent;
                }
                elements[0] = value;
            }

            public void shiftDown(int index) {
                if (index < 0 || index >= size) {
                    throw new IllegalArgumentException();
                }
                while (true) {
                    int child = (index << 1) + 1;
                    if (child >= size) {
                        return;
                    }
                    if (child + 1 < size && elements[child] > elements[child + 1]) {
                        child++;
                    }
                    if (elements[index] <= elements[child]) {
                        return;
                    }
                    swap(index, child);
                    index = child;
                }
            }

            private void swap(int first, int second) {
                long temp = elements[first];
                elements[first] = elements[second];
                elements[second] = temp;
            }

            public long remove() {
                if (isEmpty()) {
                    throw new IndexOutOfBoundsException();
                }
                long result = elements[0];
                if (size == 1) {
                    size = 0;
                    return result;
                }
                elements[0] = elements[--size];
                shiftDown(0);
                return result;
            }

            public void clear() {
                size = 0;
            }

        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(Writer out) {
            super(out);
        }

        public OutputWriter(OutputStream out) {
            super(out);
        }

    }

    static class Parser {
        private BufferedReader din;
        private StringTokenizer tokenizer;

        public Parser(InputStream in) {
            din = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(din.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}