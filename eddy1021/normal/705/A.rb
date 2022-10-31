n = gets.to_i
n.times{ |x|
  print x % 2 == 0 ? "I hate " : "I love "
  print x + 1 == n ? "it " : "that "
}